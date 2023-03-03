#ifndef ABSTRACT_SELECTABLE_H
#define ABSTRACT_SELECTABLE_H

namespace Abstract
{
    class Selectable
    {
    protected:
        bool Select = false;

    public:
        int IsSelected()
        {
            return this->Select;
        }

        void SetSelect(bool Select)
        {
            this->Select = Select;
        }
    };
}

#endif // !ABSTRACT_SELECTABLE_H