/*
Copyright (c) 2013 Aerys

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once

#include "minko/Common.hpp"
#include "android/dom/AndroidWebViewDOMEvent.hpp"
#include "minko/dom/AbstractDOMMouseEvent.hpp"

namespace minko
{
	namespace dom
	{
		class AbstractDOMElement;
	}
}

namespace android
{
	namespace dom
	{
		class AndroidWebViewDOMMouseEvent :
			public virtual minko::dom::AbstractDOMMouseEvent,
			public AndroidWebViewDOMEvent
		{
		public:
			typedef std::shared_ptr<AndroidWebViewDOMMouseEvent> Ptr;

		protected:
			AndroidWebViewDOMMouseEvent(const std::string& type, std::shared_ptr<minko::dom::AbstractDOMElement> target):
				AndroidWebViewDOMEvent(type, target),
				_clientX(0),
				_clientY(0),
				_pageX(0),
				_pageY(0),
				_screenX(0),
				_screenY(0),
				_button(0)
			{
			}

			AndroidWebViewDOMMouseEvent(AndroidWebViewDOMMouseEvent::Ptr event):
				AndroidWebViewDOMEvent(event->type(), event->target()),
				_clientX(event->clientX()),
				_clientY(event->clientY()),
				_pageX(event->pageX()),
				_pageY(event->pageY()),
				_screenX(event->screenX()),
				_screenY(event->screenY()),
				_button(event->button())
			{
			}

		public:

			static
			Ptr
			create(const std::string& type, std::shared_ptr<minko::dom::AbstractDOMElement> target)
			{
				Ptr event(new AndroidWebViewDOMMouseEvent(type, target));
				return event;
			}

			static
			Ptr
			create(AndroidWebViewDOMMouseEvent::Ptr mouseEvent)
			{
				Ptr event(new AndroidWebViewDOMMouseEvent(mouseEvent));
				return event;
			}

			int
			clientX();

			int
			clientY();

			int
			pageX();

			int
			pageY();

			int
			screenX();

			int
			screenY();

			int
			button();

			void
			clientX(int);

			void
			clientY(int);

			void
			pageX(int);

			void
			pageY(int);

			void
			screenX(int);

			void
			screenY(int);

			void
			button(int);

		private:
			int _clientX;
			int _clientY;
			int _pageX;
			int _pageY;
			int _screenX;
			int _screenY;
			int _button;
		};
	}
}