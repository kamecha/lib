//集合を表すデータ構造、根は大きさを負で持ち、子は根を正で持つ
//[0]に全体の集合の数を入れる
//swapを使用するため<utility>をインクルードする
struct UnionFind{
    vector<int>data;
    UnionFind(int size) :   data(size+1, -1){
        data[0] = size;
    }

    //集合のmerge
    //すでに同じならfalse
    bool merge(int x, int y){
        x = root(x);    y = root(y);
        if(x == y)  return false;
        //要素数の少ない方を多い方に繋げる
        if(data[y] < data[x])   swap(x, y);
        data[x] += data[y];
        data[y] = x;
        data[0]--;
        return true;
    }

    //どの集合に属しているか
    int root(int x){
        //根に繋ぎ直す
        return (data[x] < 0) ? x : (data[x] = root(data[x]));
    }

    //ある要素が属する集合の大きさ
    int size(int x){
        return -data[root(x)];
    }

    //集合の数
    int set(){
        return data[0];
    }
};

