struct segment_tree{
     //1based
     vector<int>seg,v;
     int siz;
     segment_tree(int n,vector<int>&v){
          this->v=v;
          siz=1;
          while(siz<=n)siz*=2;
          seg=vector<int>(2*siz);
          bulid(1,1,siz,1,n);
     }
     int merge(int x,int y){
         return x+y;
     }
     void bulid(int idx,int lx,int rx,int l,int r...){
         if(rx<l||lx>r)return;
         if(lx==rx){
            seg[idx]=v[lx-1];
            return;
         }
         int mid=(lx+rx)>>1;
         bulid(idx*2,lx,mid,l,r);
         bulid(idx*2+1,mid+1,rx,l,r);
         seg[idx]=merge(seg[idx*2],seg[idx*2+1]);
     }
     void update(int idx,int lx,int rx,int indx,int vl...){
         if(rx<indx||lx>indx)return;
         if(lx==rx){
            seg[idx]=vl;
            return;
         }
         int mid=(lx+rx)/2;
         update(idx*2,lx,mid,indx,vl);
         update(idx*2+1,mid+1,rx,indx,vl);
         seg[idx]=merge(seg[idx*2],seg[idx*2+1]);
     }
     int query(int idx,int lx,int rx,int l,int r...){
         if(rx<l||lx>r)return 0;
         if(l<=lx&&r>=rx)return seg[idx];
         int mid=(lx+rx)/2;
         return merge(query(idx*2,lx,mid,l,r), query(idx*2+1,mid+1,rx,l,r));
     }
     void update(int indx ,int vl...){
         update(1,1,siz,indx,vl);
     }
     int query(int l,int r){
         return query(1,1,siz,l,r);
     }


 };
