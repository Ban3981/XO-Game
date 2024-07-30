#include "ComputerPlayer.h"
#include <iostream>

            ComputerPlayer::ComputerPlayer(IDENTITY id):id(id) {}


            Move ComputerPlayer::checkEnemyPositions(const std::vector<std::vector<IDENTITY*>>& vectors) const noexcept
            {
                Move result;
                IDENTITY enemyId=flipIDENTITY(id);
                int countCmp,countEnemy,column;

                for(unsigned int i=0;i<vectors.size() && !result.valid();i++)  //check if there is a single line with two human fields and one free field
                {
                    countCmp=countEnemy=column=0;
                    countPositions(vectors[i],id,countCmp,enemyId,countEnemy,column);
                    if(countCmp==0 && countEnemy==2)
                    {
                        result=convert(i,column);
                        return result;
                    }
                }

                return result;          //return invalid result
            }


            Move ComputerPlayer::makeMove(const std::vector<std::vector<IDENTITY>>& matrix,const std::vector<std::vector<IDENTITY*>>& vectors) const noexcept
            {
                Move temp;
                try
                {
                    temp=checkMyPositions(vectors);
                }
                catch(const Move& result)                         //There is already a move which will give a victory
                {
                    return result;
                }

                Move result=checkEnemyPositions(vectors);         //first check can enemy win
                if(result.valid())
                    return result;

                result=temp;                                      //if enemy cant't,then check the best position for me currently
                if(result.valid())
                    return result;


               for(unsigned int i=0;i<matrix.size();i++)
                    for(unsigned int j=0;j<matrix[i].size();j++)
                        if(matrix[i][j]==N)
                        {
                            result.set(i,j);
                            return result;
                        }


                return result;                  //return result which isn't valid,it will happen if there is no free fields in the table
            }


            Move ComputerPlayer::convert(short int i,short int j) const noexcept
            {
                Move result;                    //convert position from member vectors to position in member matrix
                if(i>=0 && i<=2)
                    result.i=i,result.j=j;
                else if(i>=3 && i<=5)
                    result.i=j,result.j=i-3;
                else if(i==6)
                    result.i=result.j=j;
                else
                {
                    if(j==0)
                        result.i=0,result.j=2;
                    else
                        result.i=2,result.j=0;
                }

                return result;
            }


            void ComputerPlayer::countPositions(const std::vector<IDENTITY*>& vec,IDENTITY cmp,int& countCmp,IDENTITY enemy,int& countEnemy,int& column) const noexcept
            {
                for(unsigned int j=0;j<vec.size();j++)
                {
                    if(*vec[j]==cmp)
                        ++countCmp;
                    else if(*vec[j]==enemy)
                        ++countEnemy;
                    else
                        column=j;
                }
            }


            Move ComputerPlayer::checkMyPositions(const std::vector<std::vector<IDENTITY*>>& vectors) const noexcept(false)
            {
                int countCmp,countEnemy,column;
                IDENTITY enemyId=flipIDENTITY(id);

                for(unsigned int i=0;i<vectors.size();i++)      //check if there is single line with 2 computer and 1 free field;
                {
                    countCmp=countEnemy=column=0;
                    countPositions(vectors[i],id,countCmp,enemyId,countEnemy,column);
                    if(countCmp==2 && countEnemy==0)
                        throw(convert(i,column));
                }

                for(unsigned int i=0;i<vectors.size();i++)      //check if there is single line with 1 computer and 2 free fields;
                {
                    countCmp=countEnemy=column=0;
                    countPositions(vectors[i],id,countCmp,enemyId,countEnemy,column);
                    if(countCmp==1 && countEnemy==0)
                        return convert(i,column);
                }

                for(unsigned int i=0;i<vectors.size();i++)      //check if there is single line with all 3 free fields;
                {
                    countCmp=countEnemy=column=0;
                    countPositions(vectors[i],id,countCmp,enemyId,countEnemy,column);
                    if(countCmp==0 && countEnemy==0)
                        return convert(i,column);
                }

                return Move();                          //return invalid Move

            }























