/*
 * Name        : lab_9.cpp
 * Author      : Russell Powell
 * Description : Building a Spaceship Class
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 */
 
#include "lab_9.h"
#include <iostream>
#include <string>
#include <sstream>
using std::ios;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

/*
 * Class Spaceship.
 * A class to model a simple spaceship for a science fiction
 * game or story.
 */

/*
 * Set the name of this Spaceship.
 * @param string name - The name for this Spaceship
 */
void Spaceship::set_name(string name)
{
    name_ = name;
}

/*
 * Set the top speed of this Spaceship.
 * @param double top_speed - The top speed for this Spaceship in warp
 */
void Spaceship::set_top_speed(double top_speed)
{
    top_speed_ = top_speed;
}

/*
 * Set the fuel source of this Spaceship.
 * @param string fuel_source - A fuel source for this Spaceship
 */
void Spaceship::set_fuel_source(string fuel_source)
{
    fuel_source_ = fuel_source;
}

/*
 * Set the crew capacity of this Spaceship.
 * @param int crew_capacity - A crew capacity for this Spaceship
 */
void Spaceship::set_crew_capacity(int crew_capacity)
{
    crew_capacity_ = crew_capacity;
}

/*
 * Get the name of this Spaceship.
 * @return string - The name of this Spaceship
 */
string Spaceship::name() const
{
    return name_;
}

/*
 * Get the top speed of this Spaceship.
 * @return double - The top speed of this Spaceship
 */
double Spaceship::Spaceship::top_speed() const
{
    return top_speed_;
}

/*
 * Get the fuel source of this Spaceship.
 * @return string - The fuel source of this Spaceship
 */
string Spaceship::fuel_source() const
{
    return fuel_source_;
}

/*
 * Get the crew capacity of this Spaceship.
 * @return int - The crew capacity of this Spaceship
 */
int Spaceship::crew_capacity() const
{
    return crew_capacity_;   
}

/*
 * Get a string representation of this Spaceship's specifications.
 * The string will be formatted as
 * "NAME\n
 *  Top Speed:     Warp TOP_SPEED\n
 *  Fuel Source:   FUEL_SOURCE\n
 *  Crew Capacity: CREW_CAPACITY"
 * where NAME, TOP_SPEED (to two decimal places), FUEL_SOURCE, and
 * CREW_CAPACITY contain the values of the associated member variables.
 * @uses stringstream
 * @return string - A representation of this Spaceship's specifications
 */
string Spaceship::ToString() const
{
    stringstream ss;   //create variable-least imaginative name, apologies
    ss.clear();        //clear the variable of existing flag pobably non necessary
    ss.str();          //define ss as a string-can be initialized, but not required
    ss.setf(ios::fixed);
    ss.precision(2);
    ss <<name_ << "\nTop Speed:     Warp " << top_speed_ << "\nFuel Source:   "
                << fuel_source_ << "\nCrew Capacity: " << crew_capacity_;
    return ss.str();
}
