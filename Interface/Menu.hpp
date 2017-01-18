
#ifndef CLASS_MENU_HPP
#define CLASS_MENU_HPP

#include <SFML/Graphics.hpp>
#include "../Basic/Rectangle.hpp"
#include "../Basic/Point.hpp"
#include "../Basic/Material.hpp"
#include "Button.hpp"
#include <vector>

typedef enum {TOP,BOT,LEFT,RIGHT,CENTER} LOCATION;


/**
 * Classe permettante de crée un menu contenant des objets.
 */
class Menu : public Rectangle
{
	protected:
		Point origine;
		float* scaleFactors; //factors to resize pictures
		bool visible;
		int width;
		int height;
		
	private:
		Material background;
		Material leftBorder;
		Material rightBorder;
		Material topBorder;
		Material botBorder;
		Button exitButton;
	
	public:
		
		/**
		 * Création d'un menu en position x=0,y=0
		 * @param width Largeur
		 * @param height Hauteur
		 */
		Menu(const int &width,const int &height);
		
		/**
		 * Création d'un menu
		 * @param xo Position en abscisse du menu
		 * @param yo Position en ordonnée du menu
		 * @param width Largeur
		 * @param height Hauteur 
		 */
		Menu(const int &xo,const int &yo,const int &width,const int &height);
		
		
		/**
		 * Set the background
		 * @param bg 
		 */
		void setBackground(Material bg);
		
		/**
		 * Set the Material of menu borders
		 * @param border Border material
		 */
		void setLeftBorder(Material border);
		void setRightBorder(Material border);
		void setTopBorder(Material border);
		void setBotBorder(Material border);
		
		/**
		 * Set the exit button of the menu
		 */
		void setExitButton(Button knopka);
		 

		/**
		 * Display menu with all objects
		 * @param window
		 */
		void draw(sf::RenderWindow& window);
		
		/**
		 * Partial display
		 * @param window
		 */
		void draw_1(sf::RenderWindow& window);
		void draw_2(sf::RenderWindow& window);
		
		/**
		 * Set visibility to 1
		 */
		void setVisible();
		
		/**
		 * Give the visibility of the object
		 */
		bool isVisible();

		/**
		 * Fermeture du menu
		 */
		void exit();
		
		/**
		 * Update the buttons state
		 */
		void update();
		
		/**
		 * Return images configuration scale factor table
		 * @return float[2] scales factor
		 */
		float* getScaleFactor();
		
	
	
};


#endif
