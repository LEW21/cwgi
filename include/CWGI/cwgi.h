#ifndef CWGI_cwgi_h
#define CWGI_cwgi_h

#include <string>
#include <functional>
#include <vector>

namespace CWGI
{
	struct Header
	{
		std::string name;
		std::string value;

		Header() = default;

		Header(const std::string& n, const std::string& v): name(n), value(v) {}
		Header(std::string&& n, std::string&& v): name(std::move(n)), value(std::move(v)) {}

		bool empty() const {return name.empty();}
	};

	struct Request
	{
		Request();
		virtual ~Request();

		virtual Request& operator>>(Header& header) = 0;
		virtual Request& operator>>(std::string& data) = 0;
	};

	struct Response
	{
		Response();
		virtual ~Response();

		virtual Response& operator<<(const Header& header) = 0;
		virtual Response& operator<<(const std::string& data) = 0;
	};

	typedef std::function<void (Request&, Response&)> Application;

	Application chain(const std::vector<Application>&);
}

#endif
