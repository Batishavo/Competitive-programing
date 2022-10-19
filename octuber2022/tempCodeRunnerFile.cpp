 for(int k=0;k<4;k++){
                if(i+pi[k]>=0 && i+pi[k]<n && j+pj[k]>=0 && j+pj[k]<m){
                    
                    //printf("**%d %d\n", i+pi[k], j+pj[k]);

                    if(mat[i+pi[k]][j+pj[k]]=='H' || mat[i+pi[k]][j+pj[k]]=='.'){
                        //cout<<mat[i+pi[k]][j+pj[k]]<<endl;
                        if(res[i+pi[k]][j+pj[k]]==-1 ||
                           res[i+pi[k]][j+pj[k]]>res[i][j]+2)
                        {  
                            //printf("%d %d \n",i+pi[k],j+pi[k]);
                            cola.push_back({i+pi[k],j+pj[k]});
                            res[i+pi[k]][j+pj[k]]=res[i][j]+2;
                        }
                       
                        
                    }
                    else if(mat[i+pi[k]][j+pj[k]]=='W'){
                        res[i+pi[k]][j+pj[k]]=0;
                        cola.push_front({i+pi[k],j+pj[k]);
                    }
                    
                    
                }
            }