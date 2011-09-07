#ifndef CWGI_cwgi_h
#define CWGI_cwgi_h

#include <map>
#include <string>
#include <functional>
#include <vector>

namespace CWGI
{
	typedef std::pair<std::string, std::string> Header;
	typedef std::map<std::string, std::string> Headers;

	struct Request
	{
		Request();
		virtual ~Request();

		virtual Request& operator>>(Headers& headers) = 0;
		virtual Request& operator>>(std::string& data) = 0;
	};

	struct Response
	{
		Response();
		virtual ~Response();

		virtual Response& operator<<(const Headers& headers) = 0;
		virtual Response& operator<<(const std::string& data) = 0;
	};

	typedef std::function<void (Request&, Response&)> Application;

	Application chain(const std::vector<Application>&);

	typedef Application* (*ApplicationFactory)();
}

#define CWGI_ApplicationFactory extern "C" CWGI::Application* CWGI_newApplication()

#endif
