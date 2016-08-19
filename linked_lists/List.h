//created by Linux

namespace altrusian{

    class List {

    protected:
        int NumNodes = 0;

    public:
        virtual void insertAtBeginning(int value) = 0;
        virtual void insertAtEnd(int value) = 0;
        virtual void deleteFromBeginning() = 0;
        virtual void deleteFromEnd() = 0;
        virtual int size() = 0;
        virtual bool isEmpty() = 0;

    };

}