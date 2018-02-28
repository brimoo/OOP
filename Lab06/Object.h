class Object{

    int data;

    public:

        static int count;

        Object(){
            data = 0;
            count++;
        }

        Object(const Object &o1){
            data = o1.data;
            count++;
        }

};
