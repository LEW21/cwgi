#include <CWGI/cwgi.h>
#include "MessageBuffer.h"

#include <thread>

namespace CWGI
{
	Application chain(const std::vector<Application>& apps)
	{
		int size = apps.size();

		return [=](Request& req, Response& res)
		{
			MessageBuffer* requestBuffer;
			MessageBuffer* responseBuffer = 0;

			std::thread* threads[size];

			for (int i = 0; i < size; ++i)
			{
				requestBuffer = responseBuffer;
				responseBuffer = (i == size - 1) ? 0 : new MessageBuffer;

				Application app = apps.at(i);

				Request* request = requestBuffer ? requestBuffer : &req;
				Response* response = responseBuffer ? responseBuffer : &res;

				threads[i] = new std::thread([=]()
				{
					app(*request, *response);
				});
			}

			for (int i = 0; i < size; ++i)
				threads[i]->join();
		};
	}
}
