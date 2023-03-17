#ifndef CLIENT_HPP
# define CLIENT_HPP

//#include "../main.hpp"
# include <iostream>
# include <string>
# include <string.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <netdb.h>
# include <poll.h>
# include <vector>
# include <map>
#include  <sstream>
# include "../10_tools/colors.hpp"


# define BUFFER_SIZE 1024


class Client {

    struct User {
        std::string nickName;
        std::string userName;
        std::string hostName;
        std::string serverName;
        std::string realName;
        std::string userMessage;

    };
    public:
        Client();
        ~Client(); 
        void    fillDataUser( void );
        void    sendResponse( void );
        bool    getNickName( std::string toSplit );
        bool    getUserInfos( std::string toSplit);
        //-- Getters
        //std::string    getUserName( void );
        //std::string    gethostName( void );
        //std::string    getserverName( void );
        //std::string    getRealName( void );
        //std::string    getUserMessage( void );

        //-- Setters
        //void    setUserName( std::string userName );
        //void    setHostName( std::string userName );
        //void    setServerName( std::string userName );
        //void    setRealName( std::string userName );
        //void    setUserMessage( std::string userName );

    // protected:
        int socketFd;
        struct sockaddr_in          clientAddr;
        socklen_t                   clientSize;
        User                        userInfos;
        //std::vector<std::string>    cmd;
		const int			        bufferSize;
		char				        buffer[BUFFER_SIZE];
   		std::string                 authentification;
        std::string                 cmd;
		bool                        is_authentified;

};
    std::string                 removeLines(std::string);
    std::vector<std::string>    splitCommand(std::string toSplit, char sep);

#endif
