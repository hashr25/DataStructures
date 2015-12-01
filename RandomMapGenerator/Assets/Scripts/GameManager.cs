using UnityEngine;
using System.Collections;

namespace Completed
{
	using System.Collections.Generic;       //Allows us to use Lists. 
	
	public class GameManager : MonoBehaviour
	{
		
		public static GameManager instance = null;              //Static instance of GameManager which allows it to be accessed by any other script.
		public int level = 3;                                  //Current level number, expressed in game as "Day 1".
		public GameObject player;

		private BlockMapGeneration blockMapGen;                 //Store a reference to our BoardManager which will set up the level.
		private DrunkardWalk drunkardWalk;
		
		//Awake is always called before any Start functions
		void Awake()
		{
			//Check if instance already exists
			if (instance == null)
				
				//if not, set instance to this
				instance = this;
			
			//If instance already exists and it's not this:
			else if (instance != this)
				
				//Then destroy this. This enforces our singleton pattern, meaning there can only ever be one instance of a GameManager.
				Destroy(gameObject);    
			
			//Sets this to not be destroyed when reloading scene
			DontDestroyOnLoad(gameObject);
			
			//Get a component reference to the attached BoardManager script
			blockMapGen = GetComponent<BlockMapGeneration>();
			drunkardWalk = GetComponent<DrunkardWalk> ();
			
			//Call the InitGame function to initialize the first level 
			InitGame();
		}
		
		//Initializes the game for each level.
		void InitGame()
		{
			//Call the SetupScene function of the BoardManager script, pass it current level number.
			//boardScript.SetupScene(level);
			drunkardWalk.SetupScene (level);
			SetPlayer ();
		}

		//Sets Character
		void SetPlayer()
		{
			GameObject playerClone = GameObject.Find ("Player(Clone)");
			Destroy (playerClone);

			//Choose a random tile from our array of floor tile prefabs and prepare to instantiate it.
			GameObject toInstantiate = player;
			
			//Instantiate the GameObject instance using the prefab chosen for toInstantiate at the Vector3 corresponding to current grid position in loop, cast it to GameObject.
			GameObject instance =
				Instantiate (toInstantiate, new Vector3 (0f, 0f, 0f), Quaternion.identity) as GameObject;
		}
		
		void CleanBoard()
		{
			Transform boardHolder = transform.Find("Board");
			
			int childs = boardHolder.childCount;
			for (int i = childs - 1; i > 0; i--)
			{
				GameObject.Destroy(boardHolder.GetChild(i).gameObject);
			}
		}
		
		//Update is called every frame.
		void Update()
		{
			if (Input.GetKey (KeyCode.N)) 
			{
				CleanBoard();
				drunkardWalk.SetupScene (level);
				SetPlayer();
			}
			if (Input.GetKey (KeyCode.B)) 
			{
				CleanBoard();
				blockMapGen.SetupScene (level);
				SetPlayer();
			}
		}
	}
}