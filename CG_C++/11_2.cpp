//注意:代码模板中的代码将会被复制到任何新创建的文件中，编辑代码模板中的代码，让他帮你自动增加固定代码吧
            #include <iostream>
            using namespace std;
            int main()
            {
                int i,n;
                float sum=0,avg;
                cout<<"Input n:";
                cin>>n;
                float *score;
                score=new float[n];
                cout<<"Input scores:";
                for(i=0;i<n;i++)
                {
                    cin>>score[i];
                    sum+=score[i];
                }
                avg=sum/n;
                cout<<"Average:"<<avg;
                return 0;
            }


