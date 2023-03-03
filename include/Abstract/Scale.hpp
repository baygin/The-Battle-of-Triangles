#ifndef ABSTRACT_SCALE_H
#define ABSTRACT_SCALE_H

namespace Abstract
{
    class Scale
    {
    protected:
        int Height;
        int Width;

    public:
        int GetHeight()
        {
            return this->Height;
        }

        void SetHeight(int Height)
        {
            this->Height = Height;
        }

        int GetWidth()
        {
            return this->Width;
        }

        void SetWidth(int Width)
        {
            this->Width = Width;
        }
    };
}

#endif // !ABSTRACT_SCALE_H