 //if v meets a node that is previously discovered and is not its parent then update the low value
        else if( v != parent ){
            low[u] = min( low[u], disc[v] );
        }