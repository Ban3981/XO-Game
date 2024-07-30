#pragma once
#include "Constants.h"
#include <vector>

            class ComputerPlayer
            {
                    IDENTITY id;
                public:
                    ComputerPlayer(IDENTITY);
                    inline IDENTITY getIdentity() const noexcept {return id;}
                    Move makeMove(const std::vector<std::vector<IDENTITY>>&,const std::vector<std::vector<IDENTITY*>>&) const noexcept;
                private:
                    Move checkEnemyPositions(const std::vector<std::vector<IDENTITY*>>&) const noexcept;
                    Move checkMyPositions(const std::vector<std::vector<IDENTITY*>>&) const noexcept(false);
                    Move convert(short int i,short int j) const noexcept;
                    void countPositions(const std::vector<IDENTITY*>&,IDENTITY,int&,IDENTITY,int&,int&) const noexcept;
            };
