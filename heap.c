#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct member{
 int age;
 char name [ 20 ];
};
void swap ( struct member * a , struct member * b ){
 int tempData = b -> age ;
 char tempName [ 20 ];
 b -> age = a -> age ;
 a -> age = tempData;
 strcpy (tempName, b -> name );
 strcpy ( b -> name , a -> name );
 strcpy ( a -> name ,tempName);
}
void heap ( struct member heapStructure [] , int n ){
 int heapRoot,c;
 for ( int i = 1 ;i < n;i ++ ){
 c = i;
 do {
 heapRoot = (c - 1 ) / 2 ;
 if ( heapStructure [heapRoot]. age < heapStructure [c]. age ){
 swap ( & heapStructure [c], & heapStructure [heapRoot]);
 }
 c = heapRoot;
 }
 while (c != 0 );
 }
}
void main (){
 int n;
 printf ( "How many members are there in your family:" );
 scanf ( "%d" , & n);
 struct member heapStructure [n];
 for ( int i = 0 ;i < n;i ++ ){
 printf ( "enter age:" );
 scanf ( "%d" , & heapStructure [i]. age );
 printf ( "enter name:" );
 scanf ( "%s" , & heapStructure [i]. name ); 
 }
 heap (heapStructure,n);
 printf ( "Max-heap structure of family: \n " );
 for ( int i = 0 ;i < n; ++ i){
 printf ( "%d \t %s \n " , heapStructure [i]. age , heapStructure [i]. name );
 }
} 