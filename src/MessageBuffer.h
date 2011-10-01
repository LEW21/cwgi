#ifndef CWGI_MessageBuffer_h
#define CWGI_MessageBuffer_h

#include <CWGI/cwgi.h>
#include <ATL/syncqueue.h>

namespace CWGI
{
	class MessageBuffer: public Response, public Request
	{
		ATL::SyncQueue<Headers> h;
		ATL::SyncQueue<std::string> d;

	public:
		inline Response& operator<<(const Headers& headers) { h.push(headers); return *this; }
		inline Response& operator<<(const std::string& data) { d.push(data); return *this; }
		inline Request& operator>>(Headers& headers) { headers = h.pop(); return *this; }
		inline Request& operator>>(std::string& data) { data = d.pop(); return *this; }
	};
}

#endif
