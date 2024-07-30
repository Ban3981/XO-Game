#pragma once
#include <vector>
#include "Constants.h"


            class Table
            {
                    std::vector<std::vector<IDENTITY>> matrix;
                    std::vector<std::vector<IDENTITY*>> vectors;

                public:
                    Table();
                    virtual ~Table();
                    bool checkForVictory(IDENTITY) const noexcept;
                    void executeXOGame() noexcept;

                private:
                    void printToConsole() const noexcept;
                    void changeMatrix(const Move&,IDENTITY);
            };

