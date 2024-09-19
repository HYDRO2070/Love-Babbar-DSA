
        sa = left;
    }
    cout<<arr[sa]<<" "<<arr[right]<<" "<<(arr[sa] > arr[right])<<endl;
    if(right < n && arr[sa] > arr[right]){
        cout<<"hello"<<endl;
        sa = right;
    }