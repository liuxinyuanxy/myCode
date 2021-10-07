#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <ctype.h>
#define ratio 4
#define MAXN 100010
#define merge( a , b ) new_Node( a -> size + b -> size , b -> value , a , b )
#define new_Node( s , v , a , b ) ( & ( * st[ cnt++ ] = Node( s , v , a , b ) ) )
#define update( cur ) if( cur -> left -> size ) cur -> size = cur -> left -> size + cur -> right -> size , cur -> value = cur -> right -> value;

using namespace std;

struct Node
{
	int size , value;
	Node * left , * right;
	Node( int s , int v , Node * a , Node * b ) : size( s ) , value( v ) , left( a ) , right( b ) {}
	Node() {}
} * root[ MAXN ] , * null , * st[300000] , t[300000];

int n , m , cnt , x , y;
int pre[ MAXN ] , a[ MAXN ] , opt;

inline void maintain( register Node * cur )
{
	if( cur -> left -> size > cur -> right -> size * ratio ) cur -> right = merge( cur -> left -> right , cur -> right ) , st[ --cnt ] = cur -> left , cur -> left = cur -> left -> left;
	else if( cur -> right -> size > cur -> left -> size * ratio ) cur -> left = merge( cur -> left , cur -> right -> left ) , st[ --cnt ] = cur -> right , cur -> right = cur -> right -> right;
}

int find( const int & x , Node * cur )
{
	if( cur -> size == 1 ) return x == 1 ? cur -> value : -1;
	return x > cur -> left -> size ? find( x - cur -> left -> size , cur -> right ) : find( x , cur -> left );
}

void insert( const int & x , Node * cur )
{
	if( cur -> size == 1 )
		if( a[x] < a[ cur -> value ] ) cur -> left = new_Node( 1 , x , null , null ) , cur -> right = new_Node( 1 , cur -> value , null , null );
		else cur -> left = new_Node( 1 , cur -> value , null , null ) , cur -> right = new_Node( 1 , x , null , null );
	else insert( x , a[x] > a[ cur -> left -> value ] ? cur -> right : cur -> left ) , maintain( cur );
	update( cur );
}

void dispose( Node * a , Node * b )
{
	if( a -> size == 1 ) insert( a -> value , b );
	else dispose( a -> left , b ) , dispose( a -> right , b ) , st[ --cnt ] = a -> left , st[ --cnt ] = a -> right;
}

int find( const int & x )
{
	if( pre[x] == x ) return x;
	return pre[x] = find( pre[x] );
}

inline void Merge( int a , int b )
{
	if( ( x = find( a ) ) == ( y = find( b ) ) ) return;
	if( root[x] -> size > root[y] -> size ) swap( x , y );
	dispose( root[x] , root[y] ) , pre[x] = y;
}

const int H = 300000;
char s0[H] , * s1 = s0 , * s2 = s1;
#define I ( s1 == s2 &&( s2 = ( s1 = s0 ) + fread( s0 , 1 , H , stdin ) , s1 == s2 ) ? 32 : * s1++ )
inline int read()
{
    register int x = 0 , c;
    while( isspace( c = I ) );
    do
        x = x * 10 + c - 48;
    while( isdigit( c = I ) );
    return x;
}

char pf[H] , * o1 = pf , * o2 = pf + H;
#define ot( x ) ( o1 == o2 ? fwrite( pf , 1 , H , stdout ) , * ( o1 = pf ) ++= x : * o1 ++= x )
inline void print( register int x )
{
	if( x < 0 )
	{
		ot( 45 );
		x = -x;
	}
	static char s[15] , * b;
	b = s;
	if( !x ) * b ++= 48;
	for( ; x ; * b ++= x % 10 + 48 , x /= 10 );
	for( ; b-- != s ; ot( * b ) );
	ot( '\n' );
}

int main()
{
	for( register int i = 0 ; i < 300000 ; i++ ) st[i] = & t[i];
	n = read() , m = read();
	for( register int i = 1 ; i <= n ; i++ ) a[ pre[i] = i ] = read();
	while( m-- )
		pre[ find( read() ) ] = find( read() );
	null = new_Node( 0 , 0 , 0 , 0 );
	for( register int i = 1 ; i <= n ; i++ )
		if( !root[ find( i ) ] ) root[ find( i ) ] = new_Node( 1 , i , null , null );
		else insert( i , root[ find( i ) ] );
	m = read();
	while( m-- )
	{
		while( isspace( opt = I ) );
		if( opt == 'Q' ) x = read() , print( find( read() , root[ find( x ) ] ) );
		else Merge( read() , read() );
	}
	fwrite( pf , 1 , o1 - pf , stdout );
	return 0;
}