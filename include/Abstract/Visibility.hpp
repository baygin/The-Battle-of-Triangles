#ifndef ABSTRACT_VISIBILITY_H
#define ABSTRACT_VISIBILITY_H

namespace Abstract
{
    class Visibility
    {
    protected:
        bool Visible = true;

    public:
        int IsVisible()
        {
            return this->Visible;
        }

        void SetVisible(bool Visible)
        {
            this->Visible = Visible;
        }
    };
}

#endif // !ABSTRACT_VISIBILITY_H