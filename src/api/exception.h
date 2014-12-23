/**
 * @file    exception.h
 * @author  Krzysztof Okupski
 * @date    29.10.2014
 * @version 1.0
 *
 * Declaration of error class for the JSON-RPC wrapper.
 */

#ifndef MAGI_API_EXCEPTION_H
#define MAGI_API_EXCEPTION_H

#include <string>
#include <sstream>

class MagiException: public std::exception
{
private:
	int code;
	std::string msg;

public:
	explicit MagiException(int errcode, const std::string& message) {
		this->code = errcode;
		this->msg = parse(message);

	}
	~MagiException() throw() { };

	int getCode(){
		return code;
	}

	std::string getMessage(){
		return msg;
	}

	std::string parse(const std::string& in){
		std::string out = in;
		std::string pattern = ": ";
		unsigned int pos = out.find(pattern);
		if(pos <= out.size()){
			out.erase(pos, pattern.size());
			out[0] = toupper(out[0]);
		}

		return out;
	}

	virtual const char* what() const throw (){
		std::stringstream out;
		out << "Error " << code << ": " << msg;
		return out.str().c_str();
	}
};

#endif
