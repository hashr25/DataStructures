using UnityEngine;
using System.Collections;

public class ParticleRotation : MonoBehaviour {

	public float rotationSpeed = 50;

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
		transform.Rotate (0, 0, rotationSpeed * Time.deltaTime);
	}
}
