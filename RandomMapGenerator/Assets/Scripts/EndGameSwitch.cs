using UnityEngine;
using System.Collections;

public class EndGameSwitch : MonoBehaviour {

	public GameObject gameManager;
	public GameObject player;

	// Use this for initialization
	void Start () 
	{
		gameManager = GameObject.Find ("Game Manager");
		player = GameObject.Find ("Player(Clone)");
	}
	
	void OnCollisionEnter (Collision col)
	{
		Debug.Log ("Colliding with " + col.gameObject.name);
		if(col.gameObject == player)
		{
			Debug.Log("You made it!");
		}
	}
}
