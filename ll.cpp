/* imerge/ll.cpp */

#include<iostream>


namespace
{
    struct _node
    {
        _node*next_;
        int val_;
        _node( int val ):next_( NULL ),val_( val ){}
    };


    _node*
    _reverse_iterative( _node*fwd )
    {
        _node*rev = NULL;
        _node*next = NULL;
        while( fwd ){
            next = fwd->next_;
            fwd->next_ = rev;
            rev = fwd;
            fwd = next;
        }
        return rev;
    }


    _node*
    _reverse_recursive( _node*f, _node*r = NULL )
    {
        if( ! f ) return r;
        _node*next = f->next_;
        f->next_ = r;
        return _reverse_recursive( next, f );
    }



    void
    _print( _node*node )
    {
        std::cout << std::endl;
        for( ; NULL != node ; node = node->next_ )
            std::cout
                << "node @ "
                << std::showbase << std::hex << node
                << "    node->val_ == "
                << std::dec << node->val_
                << std::endl
                ;
    }


    void
    _delete( _node*node )
    {
        std::cout << std::endl ;
        while( node ){
            _node*tmp = node->next_;
            delete node;
            std::cout
                << "node @ "
                << std::showbase << std::hex << node
                << "    deleted"
                << std::endl
                ;
            node = tmp;
        }
    }

}



int
main( int /* argc */,
      char**/* argv */ )
{

    _node*phead,*pnode;
    phead = pnode = new _node( 0 );

    std::cout
        << std::endl
        << std::showbase << std::hex
        << "phead == " << phead << std::endl
        ;

    for( int n = pnode->val_ ; ++n < 6 ;
         pnode = pnode->next_ = new _node( n ) );

    _print( phead );

    phead = _reverse_iterative( phead );

    _print( phead );

    phead = _reverse_recursive( phead );

    _print( phead );

    _delete( phead );

    std::cout << std::endl ;

    return 0;
}

