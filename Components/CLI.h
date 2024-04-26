/*
 * CLI.h
 *
 *  Created on: 8 мар. 2024 г.
 *      Author: root-
 */

#ifndef INC_CLI_H_
#define INC_CLI_H_

#include <stddef.h>

#include <string>
#include <functional>
#include <map>

class CLI{
public:
	typedef std::function<std::string(std::string)> fun_t;
	void addCommand(std::string name, fun_t fun){
		commands[name] = fun;
	}
	std::string handler(std::string line){
		size_t pos = line.find(" ");
		std::string command = line.substr(0, pos);
		std::string args = line.substr(pos+1);
		auto it = commands.find(command);
		if (it == commands.end())
			return "Find command error";

		return commands[command](args);
	}
private:
	std::map<std::string,  fun_t> commands;
};

#endif /* INC_CLI_H_ */
