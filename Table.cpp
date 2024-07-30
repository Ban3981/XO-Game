#include "Table.h"
#include "User.h"
#include "ComputerPlayer.h"
#include <iostream>

                    Table::Table():matrix(3,std::vector<IDENTITY>(DIMENSION,N)),vectors(VECTOR_LIMIT,std::vector<IDENTITY*>(DIMENSION,nullptr))
                    {
                        for(int i=0;i<3;i++)
                            for(int j=0;j<3;j++)
                                vectors[i][j]=&(matrix[i][j]);

                        for(int j=0;j<3;j++)
                            for(int i=0;i<3;i++)
                                vectors[j+3][i]=&(matrix[i][j]);

                        for(int i=0;i<3;i++)
                            vectors[6][i]=&(matrix[i][i]);

                        for(int i=0,l=2;i<3;i++)
                            vectors[7][i]=&(matrix[i][l--]);
                    }



                    Table::~Table() {}


                    bool Table::checkForVictory(IDENTITY id) const noexcept
                    {

                        for(unsigned int i=0;i<vectors.size();i++)
                        {
                            int counter=0;
                            for(unsigned int j=0;j<vectors[i].size();j++)
                                if(*vectors[i][j]==id)
                                    ++counter;
                            if(counter==DIMENSION)
                                return true;
                        }
                        return false;
                    }


                    void Table::executeXOGame() noexcept
                    {
                        std::cout<<"<<<<<<<<<<Welcome to XO game>>>>>>>>>>"<<std::endl;

                        char temp=User::readAnswerFromUser("Do you want to be X(enter X) or O(enter O)?",std::vector<char>({'X','O'}));

                        IDENTITY humanID,computerID;
                        if(temp=='X')
                            humanID=X;
                        else
                            humanID=O;
                        computerID=flipIDENTITY(humanID);

                        ComputerPlayer cmpPlayer(computerID);
                        User humanPlayer(humanID);

                        char nextOnMove=User::readAnswerFromUser("Do yout want first to play(enter 1) or you will leave it to computer(enter 2)?",std::vector<char>({'1','2'}));
                        std::cout<<std::endl<<std::endl;

                        bool success=false;
                        for(int i=1;i<=9 && !success;++i)
                        {
                            if(nextOnMove=='1')
                            {
                                std::cout<<"Make a move:"<<std::endl;
                                Move move=humanPlayer.makeMove(matrix);
                                changeMatrix(move,humanPlayer.getIdentity());
                                printToConsole();
                                success=checkForVictory(humanPlayer.getIdentity());
                                if(success)
                                    std::cout<<"Congratulations,you have won!",std::getchar();
                            }
                            else
                            {
                                std::cout<<"This is computer move:"<<std::endl;
                                Move move = cmpPlayer.makeMove(matrix,vectors);
                                changeMatrix(move,cmpPlayer.getIdentity());
                                printToConsole();
                                success=checkForVictory(cmpPlayer.getIdentity());
                                if(success)
                                    std::cout<<"Computer has won!You have lost!",std::getchar();
                            }

                            if(nextOnMove=='1')
                                nextOnMove='2';
                            else
                                nextOnMove='1';

                            std::cout<<std::endl<<std::endl;
                        }

                        if(!success)
                            std::cout<<"It's a draw!"<<std::endl,std::getchar();

                        std::getchar();
                        std::getchar();
                    }


                    void Table::printToConsole() const noexcept
                    {
                        for(unsigned int i=0;i<matrix.size();i++)
                        {
                            for(unsigned int j=0;j<matrix[i].size();j++)
                            {
                                if(matrix[i][j]==X)
                                    std::cout<<'X';
                                else if(matrix[i][j]==O)
                                    std::cout<<'O';
                                else
                                    std::cout<<'-';
                                if(j<matrix[i].size()-1)
                                    std::cout<<" | ";
                            }

                            std::cout<<std::endl;
                            if(i<matrix.size()-1)
                                std::cout<<"---------";
                            std::cout<<std::endl;
                        }
                    }


                    void Table::changeMatrix(const Move& move,IDENTITY id) noexcept(false)
                    {
                        matrix[move.i][move.j]=id;
                    }
