
    int num;
    cin>>num;
    num = (pow(10,num) - 1);
    for(int i = 0;i<=num;i=i+2){
        string s = "0" + i;
        cout<<s.size()<<endl;
    }
    return 0;