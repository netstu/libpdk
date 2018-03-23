// @copyright 2017-2018 zzu_softboy <zzu_softboy@163.com>
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Created by softboy on 2018/03/08.

#ifndef PDK_KERNEL_INTERNAL_OBJECT_DEFS_PRIVATE_H
#define PDK_KERNEL_INTERNAL_OBJECT_DEFS_PRIVATE_H

#include "pdk/global/Global.h"
#include "pdk/stdext/typetraits/CallableInfoTrait.h"
#include "pdk/stdext/typetraits/Sequence.h"
#include <functional>
#include <tuple>

namespace pdk {
namespace kernel {

// forward declare class
class Object;

namespace internal {

// forward declare class
class MetaCallEvent;

void post_app_event_helper(Object *, MetaCallEvent *);

template <bool isObject, typename CallableType>
struct SlotArgNumImpl
{
   constexpr static size_t value = pdk::stdext::CallableInfoTrait<decltype(&CallableType::operator())>::argNum;
};

template <typename CallableType>
struct SlotArgNumImpl<false, CallableType>
{
   constexpr static size_t value = pdk::stdext::CallableInfoTrait<CallableType>::argNum;
};

template <typename CallableType>
struct SlotArgNum : SlotArgNumImpl<std::is_class<std::remove_reference_t<CallableType>>::value, CallableType>
{};

} // internal
} // kernel
} // pdk

#define PDK_DEFINE_SIGNAL_BINDER(signalName) public:\
   pdk::kernel::signal::Connection\
   connect##signalName##Signal(const std::function<signalName##HandlerType> &callable,\
   const pdk::kernel::Object *context = nullptr,\
   pdk::ConnectionType connectionType = pdk::ConnectionType::AutoConnection);\
   template <typename RetType, typename Class> \
   pdk::kernel::signal::Connection\
   connect##signalName##Signal(const pdk::kernel::Object *receiver, RetType Class::* memberFunc,\
   pdk::ConnectionType connectionType = pdk::ConnectionType::AutoConnection)\
   {\
      using ReturnType = typename pdk::stdext::CallableInfoTrait<signalName ## HandlerType>::ReturnType;\
      constexpr size_t signalArgNum = pdk::stdext::CallableInfoTrait<signalName ## HandlerType>::argNum;\
      constexpr size_t slotArgNum = pdk::stdext::CallableInfoTrait<decltype(memberFunc)>::argNum;\
      PDK_STATIC_ASSERT_X(signalArgNum >= slotArgNum, "slot handler argument number must less or equal than signal");\
      if (!m_## signalName ##Signal) {\
         m_## signalName ##Signal.reset(new pdk::kernel::signal::Signal<signalName ## HandlerType>);\
      }\
      if (connectionType == pdk::ConnectionType::AutoConnection) {\
         if (getThread() == receiver->getThread()) {\
            connectionType = pdk::ConnectionType::DirectConnection;\
         } else {\
            connectionType = pdk::ConnectionType::QueuedConnection;\
         }\
      }\
      switch(connectionType) {\
      case pdk::ConnectionType::DirectConnection:{\
         return m_## signalName ##Signal->connect([memberFunc, receiver](auto&&... args) -> ReturnType{\
            return std::apply(std::mem_fn(memberFunc),\
                       std::tuple_cat(std::tuple<Class *>(dynamic_cast<Class *>(const_cast<Object *>(receiver))),\
                       pdk::stdext::extract_first_n_items<slotArgNum>(std::make_tuple(args...))));\
         });\
      }\
      case pdk::ConnectionType::QueuedConnection: {\
         auto wrapper = [memberFunc, receiver](auto&&... args) -> ReturnType{\
            pdk::kernel::internal::post_app_event_helper(const_cast<Object *>(receiver), new pdk::kernel::internal::MetaCallEvent([=](){\
               std::apply(std::mem_fn(memberFunc),\
               std::tuple_cat(std::tuple<Class *>(dynamic_cast<Class *>(const_cast<Object *>(receiver))),\
               pdk::stdext::extract_first_n_items<slotArgNum>(std::make_tuple(args...))));\
            }));\
         };\
         return m_## signalName ##Signal->connect(wrapper);\
      }\
      default:\
         PDK_UNREACHABLE();\
      }\
   }\
   template <typename SlotFuncType>\
   pdk::kernel::signal::Connection connect## signalName ##Signal(\
         SlotFuncType &&callable,\
         const pdk::kernel::Object *context,\
         pdk::ConnectionType connectionType = pdk::ConnectionType::AutoConnection)\
   {\
      PDK_STATIC_ASSERT_X(pdk::stdext::IsCallable<SlotFuncType>::value, "Slot must be callable type");\
      using ReturnType = typename pdk::stdext::CallableInfoTrait<signalName ## HandlerType>::ReturnType;\
      constexpr size_t signalArgNum = pdk::stdext::CallableInfoTrait<signalName ## HandlerType>::argNum;\
      constexpr size_t slotArgNum = pdk::kernel::internal::SlotArgNum<SlotFuncType>::value;\
      PDK_STATIC_ASSERT_X(signalArgNum >= slotArgNum, "slot handler argument number must less or equal than signal");\
      if (!m_## signalName ##Signal) {\
         m_## signalName ##Signal.reset(new pdk::kernel::signal::Signal<signalName ## HandlerType>);\
      }\
      if (nullptr == context) {\
         context = this;\
      }\
      if (connectionType == pdk::ConnectionType::AutoConnection) {\
         if (getThread() == context->getThread()) {\
            connectionType = pdk::ConnectionType::DirectConnection;\
         } else {\
            connectionType = pdk::ConnectionType::QueuedConnection;\
         }\
      }\
      switch(connectionType) {\
      case pdk::ConnectionType::DirectConnection:{\
         return m_## signalName ##Signal->connect([callable](auto&&... args) -> ReturnType{\
            return std::apply(callable, pdk::stdext::extract_first_n_items<slotArgNum>(std::make_tuple(args...)));\
         });\
      }\
      case pdk::ConnectionType::QueuedConnection: {\
         auto wrapper = [callable, context](auto&&... args) -> ReturnType{\
            pdk::kernel::internal::post_app_event_helper(const_cast<Object *>(context), new pdk::kernel::internal::MetaCallEvent([=](){\
               std::apply(callable, pdk::stdext::extract_first_n_items<slotArgNum>(std::make_tuple(args...)));\
            }));\
         };\
         return m_## signalName ##Signal->connect(wrapper);\
      }\
      default:\
         PDK_UNREACHABLE();\
      }\
   }\
   protected: \
   std::shared_ptr<pdk::kernel::signal::Signal<signalName##HandlerType>> m_##signalName##Signal

#define PDK_DEFINE_SIGNAL_EMITTER(signalName) \
   template <typename ...ArgTypes>\
   void emit##signalName##Signal(ArgTypes&& ...args)\
   {\
      if (m_##signalName##Signal) {\
         (*m_##signalName##Signal)(std::forward<ArgTypes>(args)...);\
      }\
   }\

#endif // PDK_KERNEL_INTERNAL_OBJECT_DEFS_PRIVATE_H
