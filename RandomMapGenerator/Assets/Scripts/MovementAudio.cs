using UnityEngine;
using System.Collections;

public class MovementAudio : MonoBehaviour 
{
	public AudioClip[] footsteps;
	public AudioClip jump;
	public AudioClip land;

	// Use this for initialization
	void Start () {
	
	}

	void PlayFootstep()
	{
		GetComponent<AudioSource>().clip = footsteps [Random.Range (0, footsteps.Length)];
		GetComponent<AudioSource>().Play ();
	}
	
	void Jump()
	{
		GetComponent<AudioSource>().clip = jump;
		GetComponent<AudioSource>().Play ();
	}
	
	void Land()
	{
		GetComponent<AudioSource>().clip = land;
		GetComponent<AudioSource>().Play ();
	}
}
