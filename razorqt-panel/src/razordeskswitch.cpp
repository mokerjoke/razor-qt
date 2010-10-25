#ifndef RAZORDESKSWITCH_CPP
#define RAZORDESKSWITCH_CPP
#include "razordeskswitch.h"
#include "razor.h"
/**
 * @file razordeskswitch.cpp
 * @author Christopher "VdoP" Regali
 * @brief implements Razordeskswitch and Razordeskswitchgui
 */

/**
 * @brief the event handler
 */
bool Razordeskswitch::handleEvent(XEvent* _event)
{
    if (_event->type == PropertyNotify)
    {
        desktop = Razor::getInstance().get_Xfitman()->getActiveDesktop() +1;
        if (desktop != gui->value())
            gui->setValue(desktop);
    }

    return false;
}


/**
 * @brief the constructor
 */

Razordeskswitch::Razordeskswitch(int _bar): Razorplugin(_bar)
{
    //first we make th  e gui
    gui = new Razordeskswitchgui(this);
    //then we get an actual screen to set the gui right
    desktop = Razor::getInstance().get_Xfitman()->getActiveDesktop() + 1;
    //now we set the gui to the appropriate values
    gui->setValue(desktop);
    gui->setMinimum(1);
    gui->setMaximum(Razor::getInstance().get_Xfitman()->getNumDesktop());
    gui->setPrefix("Desktop ");
    gui->setFixedWidth(100);
    gui->setFixedHeight(Razor::getInstance().get_looknfeel()->getValue("razorbar_height").toInt()-6);
    //then we connect the signal to the slot
    connect(gui,SIGNAL(changeDesk(int)),this, SLOT(switchDesktop(int)));
    //finally we add the gui to the given bar
    Razor::getInstance().get_gui()->addWidget(gui,_bar,0,Qt::AlignLeft);
    //and make us get events!
    Razor::getInstance().get_events()->registerCallback(this);
    
}

/**
 * @brief the destructor
 */
Razordeskswitch::~Razordeskswitch()
{
    Razor::getInstance().get_events()->unregisterCallback(this);
    delete gui;
}

/**
 * @brief this switches our desktop to the given one
 */
void Razordeskswitch::switchDesktop(int _newdesk)
{
    Razor::getInstance().get_Xfitman()->setActiveDesktop(_newdesk - 1);
}


/**
 * @brief constructor for gui
 */
Razordeskswitchgui::Razordeskswitchgui(Razorplugin* _owner)
{
    owner = _owner;
}

/**
 * @brief manages the mousewheel-events
 */
void Razordeskswitchgui::wheelEvent(QWheelEvent* _event)
{
    int numDegrees = _event->delta() / 8;
    int numSteps = numDegrees / 15;
    int oldval = value();
    if (oldval + numSteps < minimum() || oldval+numSteps > maximum())
        numSteps %= (maximum() - minimum());
    int newval = oldval + numSteps;
    setValue(newval);
    emit changeDesk(newval);
}




#endif
