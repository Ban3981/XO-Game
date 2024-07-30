#pragma once

            enum IDENTITY {X=1,O=2,N=3};
            inline IDENTITY flipIDENTITY(IDENTITY id)
            {
                if(id==X) return O;
                else return X;
            }

            const int DIMENSION=3;
            const int VECTOR_LIMIT=8;

            struct Move
            {
                int i,j;
                Move():i(-1),j(-1) {}
                Move(int i,int j):i(i),j(j) {}
                Move(const Move&) = default;
                inline bool valid() const noexcept {return (i!=-1 && j!=-1);}
                inline void set(int a,int b) noexcept {i=a;b=j;}
            };
