#include "User.h"
#include <iostream>

            User::User(IDENTITY id):id(id) {}


            Move User::makeMove(const std::vector<std::vector<IDENTITY>>& matrix) const noexcept
            {
                Move result;
                std::cout<<"Enter index values for your move:";
                do
                {
                    std::cin>>result.i>>result.j;
                }while(result.i<0 || result.j<0 || result.i>=DIMENSION || result.j>=DIMENSION || matrix[result.i][result.j]!=N);  //check index values

                return result;
            }


            char User::readAnswerFromUser(const std::string& message,std::vector<char> correctAnswers) noexcept
            {
                auto funct=[&correctAnswers](char x)->bool
                {
                    for(unsigned i=0;i<correctAnswers.size();i++)
                        if(x==correctAnswers[i])
                            return true;
                    return false;
                };

                std::cout<<message;
                char result;
                do
                {
                    std::cin>>result;
                }while(!funct(result));

                return result;
            }
