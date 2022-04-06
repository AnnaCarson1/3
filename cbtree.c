#include "DS.h"

/*
  p-ийн зааж буй CBTree-д x утгыг оруулна
*/
void cb_push(CBTree *p, int x)
{
        p -> cb_arr [ p -> cb_len ] = x ;
        p -> cb_len ++ ;
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй оройны зүүн хүүгийн индексийг буцаана.
  Зүүн хүү байхгүй бол -1 буцаана.
*/
int cb_left(const CBTree *p, int idx)
{
        if ( ( idx + 1 ) * 2 - 1 <= p -> cb_len - 1 ) return ( ( idx + 1 ) * 2 - 1 ) ;
        else return -1 ;
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй оройны баруун хүүгийн индексийг буцаана.
  Баруун хүү байхгүй бол -1 буцаана.
*/
int cb_right(const CBTree *p, int idx)
{
        if ( ( idx + 1 ) * 2 <= p -> cb_len - 1 ) return ( ( idx + 1 ) * 2 ) ;
        else return -1 ;
}

/*
  p-ийн зааж буй CBTree-с x тоог хайн
  хамгийн эхэнд олдсон индексийг буцаана.
  Олдохгүй бол -1 утгыг буцаана.
*/
int cb_search(const CBTree *p, int x)
{
        int i ;
        int pos = -1 ;
        for ( i = 0 ; i < p -> cb_len ; i ++ ) {
            if ( p -> cb_arr [ i ] == x ) {
                pos = i ;
                break ;
            }
        }
        return pos ;
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй зангилаанаас дээшхи бүх өвөг эцэгийг олох үйлдлийг хийнэ.
  Тухайн орой өөрөө өвөг эцэгт орохгүй.
  Өвөг эцэг бүрийг нэг шинэ мөрөнд хэвлэнэ. Өвөг эцэгийг доороос дээшхи дарааллаар хэвлэнэ.
*/
void cb_ancestors(const CBTree *p, int idx)
{
        while ( idx != 0 ) {
            idx = ( idx - 1 ) / 2 ;
            printf ( "%d\n" , p -> cb_arr [ idx ] ) ;
        }
}

/*
  p-ийн зааж буй CBTree-ийн өндрийг буцаана
*/
int cb_height(const CBTree *p)
{
        if ( p -> cb_len == 0 ) return 0;
        int h = 1 ;
        int x = 1 , y = 2 ;
        while ( h > 0 ) {
            if ( x <= p -> cb_len && p -> cb_len <= y - 1 ) return h ;
            h ++ ;
            x *= 2 ;
            y *= 2 ;
        }
}

/*
  p-ийн зааж буй CBTree-д idx оройны ах, дүү оройн дугаарыг буцаана.
  Тухайн оройн эцэгтэй адил эцэгтэй орой.
  Ах, дүү нь байхгүй бол -1-г буцаана.
*/
int cb_sibling(const CBTree *p, int idx)
{
        if ( idx == 0 ) return -1 ;
        if ( idx % 2 == 0 ) return idx - 1 ;
        else {
            if ( idx == p -> cb_len - 1 ) return -1 ;
            else return ( idx + 1 ) ;
        }
}

/*
  p-ийн зааж буй CBTree-г idx дугаартай зангилаанаас эхлэн preorder-оор хэвлэ.
  Орой бүрийг нэг шинэ мөрөнд хэвлэнэ.
*/
void cb_preorder(const CBTree *p, int idx)
{
        if ( idx >= p -> cb_len ) return ;
        printf ( "%d\n" , p -> cb_arr [ idx ] ) ;
        cb_preorder ( p , ( idx + 1 ) * 2 - 1 ) ;
        cb_preorder ( p , ( idx + 1 ) * 2 ) ;
}

/*
  p-ийн зааж буй CBTree-г idx дугаартай зангилаанаас эхлэн in-order-оор хэвлэ.
  Орой бүрийг нэг шинэ мөрөнд хэвлэнэ.
*/
void cb_inorder(const CBTree *p, int idx)
{
        if ( idx >= p -> cb_len ) return ;
        cb_inorder ( p , ( idx + 1 ) * 2 - 1 ) ;
        printf ( "%d\n" , p -> cb_arr [ idx ] ) ;
        cb_inorder ( p , ( idx + 1 ) * 2 ) ;
}

/*
  p-ийн зааж буй CBTree-г idx дугаартай зангилаанаас эхлэн post-order-оор хэвлэ.
  Орой бүрийг нэг шинэ мөрөнд хэвлэнэ.
 */
void cb_postorder(const CBTree *p, int idx)
{
        if ( idx >= p -> cb_len ) return ;
        cb_postorder ( p , ( idx + 1 ) * 2 - 1 ) ;
        cb_postorder ( p , ( idx + 1 ) * 2 ) ;
        printf ( "%d\n" , p -> cb_arr [ idx ] ) ;
}

/*
  p-ийн зааж буй CBTree-с idx дугаартай зангилаанаас доошхи бүх навчийг олно.
  Навч тус бүрийн утгыг шинэ мөрөнд хэвлэнэ.
  Навчыг зүүнээс баруун тийш олдох дарааллаар хэвлэнэ.
*/
void cb_leaves(const CBTree *p, int idx)
{
        if ( idx >= p -> cb_len ) return ;
        if ( ( idx + 1 ) * 2 - 1 > p -> cb_len - 1 ) {
            printf ( "%d\n" , p -> cb_arr [ idx ] ) ;
        }
        cb_leaves ( p , ( idx + 1 ) * 2 - 1 ) ;
        cb_leaves ( p , ( idx + 1 ) * 2 ) ;
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй оройноос доошхи бүх үр садыг хэвлэнэ.
  Тухайн орой өөрөө үр сад болохгүй.
  Үр, сад бүрийг нэг шинэ мөрөнд хэвлэнэ. Үр садыг pre-order дарааллаар хэлэх ёстой.
*/
void cb_descendants(const CBTree *p, int idx)
{
        cb_preorder ( p , ( idx + 1 ) * 2 - 1 ) ;
        cb_preorder ( p , ( idx + 1 ) * 2 ) ;
}


/*
  p-ийн зааж буй Tree-д хэдэн элемент байгааг буцаана.
  CBTree-д өөрчлөлт оруулахгүй.
*/
int cb_size(const CBTree *p)
{
        return ( p -> cb_len ) ;
}


/*
  p-ийн зааж буй CBTree-д x утгаас үндэс хүртэлх оройнуудын тоог буцаана.
  x тоо олдохгүй бол -1-г буцаана.
*/
int cb_level(const CBTree *p, int x)
{
        int pos = cb_search ( p , x ) ;
        if ( pos == -1 ) return -1 ;
        if ( pos == 0 ) return 0 ;
        int h = 1 ;
        int a = 2 , b = 4 ;
        while ( h > 0 ) {
            if ( a - 1 <= pos && pos <= b - 2 ) return h ;
            h ++ ;
            a *= 2 ;
            b *= 2 ;
        }
}

