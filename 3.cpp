int gameWithCells(int n, int m) {
        if(n%2 == 0 && m%2 == 0){
            return (n*m)/4;
        }
        else if((n%2 == 1 && m%2 == 0) || (n%2 == 0 && m%2 == 1)){
            if(n%2 == 1){
                return ((n+1)*m)/4;
            }
            if(m%2 == 1){
                return ((m+1)*n)/4;
            }
        }
        else{
            return ((m+1)*(n+1))/4;
        }
}
