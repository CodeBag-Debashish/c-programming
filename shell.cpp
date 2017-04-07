// built_in 
// cd
// exit

// No i/o redirection + No pipes
// code based on cpp STL and some UNIX functions


#include <bits/stdc++.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#define delim " \t\r\n\a"
const char ** _convert(std::vector<string> &argument_list) {
	const char **argv = new const char* [argument_list.size()+1];
	//*argv[argument_list.size()+1]
	for (int j = 0;j<argument_list.size();j++)
		argv[j] = argument_list[j].c_str();
	argv[argument_list.size()] = NULL;
	return argv;
}

// builtin-code
//---------------------------------------------------------------------
int my_shell_cd(char **args);
int my_shell_exit(char **args);
char *builtin_str[] = {
  "cd",
  "exit"
};
int (*builtin_func[]) (char **) = {
	&my_shell_cd,
	&my_shell_exit
};
int lsh_num_builtins() {
	return sizeof(builtin_str) / sizeof(char *);
}
int my_shell_cd(char **args) {
	if (args[1] == NULL) {
		fprintf(stderr, "my_shell: expected argument to \"cd\"\n");
	}else{
		if(chdir(args[1]) != 0) {
			perror("my_shell");
		}
	}
	delete[](args);
	return 1;
}
int my_shell_exit(char **args) {
	//free(args);
	delete[](args);
	return 0;
}
//-------------------------------------------------------------
int run_program_command(vector<string> &argument_list) {
	pid_t pid, wpid;
	int status;
	pid = fork();
	const char ** argv = _convert(argument_list);
	if(pid == 0) {
	    if (execvp(argv[0],(char **)argv) == -1) {
			perror("my_shell");
	    }
	    delete[](argv);
	    exit(EXIT_FAILURE);
	}else if(pid < 0) {
		perror("my_shell");
	}else {
		delete[](argv);
	    do {
			wpid = waitpid(pid, &status, WUNTRACED);
	    }while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	
	return 1;
}
int run_command(std::vector<string> &argument_list) {
	if(argument_list.size() == 0) {
		return 1;
	}
	for (int i = 0; i < lsh_num_builtins(); i++) {
		if (strcmp(argument_list[0].c_str(), builtin_str[i]) == 0) {
			return (*builtin_func[i])((char **)(_convert(argument_list)));
		}
	}
	return run_program_command(argument_list);
}
void tokenize_user_input(string & user_input,std::vector<string> & argument_list) {
	size_t prev_pos = 0, pos;
	while ((pos = user_input.find_first_of(delim, prev_pos)) != std::string::npos) {
		if (pos > prev_pos)
			argument_list.push_back(user_input.substr(prev_pos, pos-prev_pos));
		prev_pos= pos+1;
	}
	if (prev_pos< user_input.length())
		argument_list.push_back(user_input.substr(prev_pos, std::string::npos));
}
void get_user_input(string & user_input) {
	while(true) {
		char c = getchar();
		if (c == EOF || c == '\n') {
			break;
		} else {
			user_input = user_input + c;
		}
	}
}
int main(int argc,char **argv) {
	string user_input;
	std::vector<string> argument_list;
	int ok=1;
	while(ok) {
		cout << "my_shell$>";
		get_user_input(user_input);
		tokenize_user_input(user_input,argument_list);
		ok = run_command(argument_list);	
		user_input.clear();
		argument_list.clear();
	}
}

