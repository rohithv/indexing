
int m=10;

struct node {
int n;
int elems[mx-1];
struct node* childs[mx];
int lf;

}

struct node * split(struct node * nd){

struct node *tmp = (struct node*) malloc (sizeof(struct node));
tmp->n=m-1;

int i;

for(i=0;i<m-1;i++){
tmp->elems[i]=nd->elems[i+m];
tmp->childs[i]=nd->childs[i+m];
}
tmp->childs[m-1]=head->childs[2*m-1];

nd->n=m-1;
tmp->lf=nd->lf;

return tmp;
}


int find_pos(struct node* nd, int val){
int i=0;
while(i<(nd->n) && nd->elems[i]<val) i++;

return i;
}




int insert(struct node *head, int val){

if(head==NULL){
struct node *tmp = (struct node*) malloc (sizeof(struct node));
tmp->n=1;
tmp->lf=1;
tmp->elems[0]=val;
return 1;
}


if(head->n==2*m-1){
//
struct node *tmp = (struct node*) malloc (sizeof(struct node));
tmp->n=1;
tmp->elems[0]=head->elems[m-1]; //mth elem
tmp->childs[0]=head;
tmp->childs[1]=split(head);
tmp->lf=0;
head=tmp;
}

struct node *hd=head;

while(!hd->lf){
int pos=find_pos(hd,val);
/*if(pos!=hd->n && hd->elems[pos]==val){
printf("elem already present");
return 0;}
*/

if(hd->childs[pos]->n == 2*m-1){
struct node *tmp =hd;
int i;

int topbring=hd->childs[pos]->elems[m-1];

hd->childs[n+1]=hd->childs[n];
for(i=(hd->n)-1;i>pos;i--){
hd->elems[i]=hd->elems[i-1];
hd->childs[i]=hd->childs[i-1];
}
hd->elems[pos+1]=topbring;
hd->childs[pos+1]=split(hd->childs[pos]);

pos=find_pos(hd,val);

}

if(pos!=hd->n && hd->elems[pos]==val){
printf("elem already present");
return 0;}

hd=hd->childs[pos];

}

int pos=find_pos(hd,val);
int i;
for(i=(hd->n)-1;i>pos;i--)
hd->elems[i]=hd->elems[i-1];

hd->elems[pos]=val;
return 1;

//insert in leaf

}

/////////////////---delete

void delete(struct node *hd, int val){

int pos=find_pos(hd,val);

if(pos!=n && hd->elems[pos]==val){

if(hd->lf){
for(i=pos;i<(hd->n)-1;i++){
hd->elems[i]=hd->elems[i+1];
}
hd->n=hd->n-1;
return;
}

else if( pos<n && hd->childs[pos+1]->n >=m){
//take elem from right child and call rec.
}else if(pos>0 && hd->childs[pos-1] >=m){
//take elem from left child and call rec.
}else{
// merge pos and pos+1 child with val.
}

/////else get replaced from childs--

} 
else{

struct node * chld=hd->childs[pos];
if(chld->n >=m)
{
delete(chld,val);
return;
}

if( pos<n && hd->childs[pos+1]->n >=m){
//get extra from neighbour
}else if(pos>0 && hd->childs[pos-1] >=m){
//get child from left sibling.
}else if(pos<n){
//merge with right sibling.
}
else{
// merge with left sibling.
}


}

}


