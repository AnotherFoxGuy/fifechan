#include <fifechan/widgets/circularcontainer.hpp>
#include <cmath>

namespace fcn
{
    CircularContainer::CircularContainer(int radius, float spacing)
    :
    mRadius(radius),
    mSpacing(spacing),
    mUsedSlots(0)
    {
        int diameter = 2 * radius;
        
        setSize(diameter, diameter);
        
        calculateAvailableSlots(mRadius);
    }
    
    CircularContainer::~CircularContainer()
    {
    }
    
    void CircularContainer::setRadius(int radius)
    {
        int diameter = 2 * radius;
        mRadius = radius;
        
        setSize(diameter, diameter);
        calculateAvailableSlots(mRadius);
        relayout();
    }
    
    void CircularContainer::widgetAdded(const ContainerEvent& containerEvent)
    {   
        AutoLayoutContainer::widgetAdded(containerEvent);  
        
        if(containerEvent.getContainer() == this)
        {
            Widget *added = containerEvent.getSource();
            
            layoutAddedChild(added);   
        }
    }
    
    void CircularContainer::widgetRemoved(const ContainerEvent& containerEvent)
    {
        AutoLayoutContainer::widgetRemoved(containerEvent);
        
        if(containerEvent.getContainer() == this)
        {
            relayout();

            if(!mQueuedWidgets.empty())
            {   
                Widget* widget = mQueuedWidgets.front();
                        
                add(widget);
                
                mQueuedWidgets.pop();
            }
        }
    }
    
    void CircularContainer::widgetShown(const Event& event)
    {
    }
    
    void CircularContainer::widgetHidden(const Event& event)
    {
    }
    
    void CircularContainer::relayout()
    {
        mUsedSlots = 0;
        
        std::list<Widget*>::iterator currChild(mChildren.begin());
        std::list<Widget*>::iterator endChildren(mChildren.end());
        
        for(; currChild != endChildren; ++currChild)
        {
            layoutAddedChild(*currChild);
        }   
    }
    
    void CircularContainer::add(Widget* widget)
    {
        if(mUsedSlots == mAvailableSlots.size())
        {
            mQueuedWidgets.push(widget);
        }
        else
        {
            Container::add(widget);
        }
    }
    
    void CircularContainer::setWidth(int width)
    {
        setRadius(width);
    }
    
    void CircularContainer::setHeight(int height)
    {
        setRadius(height);
    }
    
    void CircularContainer::calculateAvailableSlots(int radius)
    {
        std::vector<Position> temp;
        mAvailableSlots.swap(temp);
        
        int centerX = radius;
        int centerY = radius;
        int totalSlots = static_cast<int>(2 * PI / mSpacing);
        
        float angle;
        int x, y;
        
        for(int i = 0; i < totalSlots; i++)
        {
            angle = mSpacing * i;
            x = centerX + radius * cos(angle - PI / 2.0);
            y = centerY + radius * sin(angle - PI / 2.0);
            mAvailableSlots.push_back(Position(x, y));
        }
    }
    
    void CircularContainer::layoutAddedChild(Widget* added)
    {
        Position& pos = mAvailableSlots[mUsedSlots];
        
        int width = added->getWidth();
        int height = added->getHeight();
        
        added->setPosition(pos.first - (width / 2) , pos.second - (height / 2));
        
        keepChildInBounds(added);
        
        mUsedSlots++;
    }
    
    void CircularContainer::keepChildInBounds(Widget* widget)
    {
        const Rectangle& childDimension = widget->getDimension();
        
        if(childDimension.x < 0)
            widget->setX(0);
        
        if(childDimension.y < 0)
            widget->setY(0);
        
        if(childDimension.x + childDimension.width > mDimension.width)
            widget->setX(mDimension.width - childDimension.width);
        
        if(childDimension.y + childDimension.height > mDimension.height)
            widget->setY(mDimension.height - childDimension.height);
    }
};