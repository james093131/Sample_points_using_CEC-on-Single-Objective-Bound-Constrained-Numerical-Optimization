#include "CEC21.hpp"

typedef vector<char> c1d;
typedef vector<c1d> c2d;
typedef vector<c2d> c3d;
typedef vector<c3d> c4d;
typedef vector<int> i1d;
typedef vector<i1d> i2d;
typedef vector<i2d> i3d;
typedef vector<i3d> i4d;
typedef vector<double>d1d;
typedef vector<d1d> d2d;
typedef vector<d2d> d3d;
typedef vector<d3d> d4d;

class Sample_point :CEC21{
    private:
        d2d Position;
        d1d Fitness;
        int max = 100;
        int min = -100;
    public:
        void CUT_Solution_Space(int DIM,int Verify_Point) 
        {
            cout << scientific << setprecision(2);
            int K = pow(Verify_Point,DIM);
            Position.assign(K,d1d(DIM));
            Fitness.resize(K,0);

            double Deviation = (max - min )/(Verify_Point-1);
            d1d Value(Verify_Point);
            for(int i=0;i<Verify_Point;i++)
            {
                Value[i] = min + Deviation*i;
            }
           
            d1d counter(DIM,0);
            for(int i=0;i<K;i++)
            {
                int P = DIM-1;
                int k = 0;
                
                for(int j=0;j<DIM;j++)
                {
               
                    Position[i][j] = Value[counter[k]];
                    k++;
                }

                counter[P] ++;
                while(counter[P] == Verify_Point)
                {
                    counter[P] = 0;
                    
                    P = P-1;
                    if(P < 0 )
                        break;
                    counter[P]++;
                   
                }

            }
    
        }
        void Print(int DIM,int Verify_points)
        {
            for(int i=0;i<pow(Verify_points,DIM);i++)
            {
                for(int j=0;j<DIM;j++)
                {
                    cout<<Position[i][j]<<' ';    
                }
                cout<<Fitness[i]<<endl;
            }
        }
        void run(int DIM ,int F,int F_T,int Verify_points)
        {
            for(int i=0;i<pow(Verify_points,DIM);i++)
            {
                CEC21::cec21_cal(&Position[i][0],Fitness[i],DIM,F,F_T);
            }
        }
};
int main(int argc,const char *argv[])
{
    int Verify_Point = atoi(argv[1]);
    int DIM = atoi(argv[2]);
    int Function_Number = atoi(argv[3]);
    int Function_Transform = atoi(argv[4]);

    Sample_point sample;
    sample.CUT_Solution_Space(DIM,Verify_Point);
    sample.run(DIM,Function_Number,Function_Transform,Verify_Point);
    sample.Print(DIM,Verify_Point);
    

}