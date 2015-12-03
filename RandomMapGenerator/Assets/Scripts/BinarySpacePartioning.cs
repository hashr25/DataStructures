using UnityEngine;
using System.Collections;
using System.Collections.Generic;

/**
 * Algorithm taken from http://gamedevelopment.tutsplus.com/tutorials/how-to-use-bsp-trees-to-generate-game-maps--gamedev-12268
 */

public class BinarySpacePartioning : MonoBehaviour 
{
	public class Room
	{
		int x, y, width, height;

		public Room(int x, int y, int width, int height)
		{
			this.x = x;
			this.y = y;
			this.width = width;
			this.height = height;
		}
	}

	public class Leaf
	{
		public int  MinimumLeafSize = 6;

		public int x, y, width, height;
		public Leaf leftChild, rightChild;
		public Room room;
		public List<Room> halls;

		public Leaf(int x, int y, int width, int height) 
		{
			this.x = x;
			this.y = y;
			this.width = width;
			this.height = height;
			leftChild = null;
			rightChild = null;
		}

		public bool Split()
		{
			// begin splitting the leaf into two children
			if (leftChild != null || rightChild != null)
				return false; // we're already split! Abort!
			
			// determine direction of split
			// if the width is >25% larger than height, we split vertically
			// if the height is >25% larger than the width, we split horizontally
			// otherwise we split randomly
			bool splitH = System.Convert.ToBoolean(Random.Range (0, 1));
			int max;

			if (width > height && width / height >= 1.25)
				splitH = false;
			else if (height > width && height / width >= 1.25)
				splitH = true;

			if (splitH) 
			{
				max = height - MinimumLeafSize;
			} 
			else 
			{
				max = width - MinimumLeafSize;
			}

			if (max <= MinimumLeafSize)
				return false; // the area is too small to split any more...
			
			int split = Random.Range(MinimumLeafSize, max); // determine where we're going to split
			
			// create our left and right children based on the direction of the split
			if (splitH)
			{
				leftChild = new Leaf(x, y, width, split);
				rightChild = new Leaf(x, y + split, width, height - split);
			}
			else
			{
				leftChild = new Leaf(x, y, split, height);
				rightChild = new Leaf(x + split, y, width - split, height);
			}
			return true; // split successful!
		}
	}
}
