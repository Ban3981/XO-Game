#pragma once
#include <vector>
#include <string>
#include "Constants.h"

            class User
            {
                    IDENTITY id;
                public:
                     User(IDENTITY);
                     Move makeMove(const std::vector<std::vector<IDENTITY>>&) const noexcept;
                     inline IDENTITY getIdentity() const noexcept {return id;}
                     static char readAnswerFromUser(const std::string&,std::vector<char>) noexcept;
            };

