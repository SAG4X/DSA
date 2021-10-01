<script>
let iterativeFunction = function (arr, x) {

	let start=0, end=arr.length-1;
		
	while (start<=end){

		// Find the mid index
		let mid=Math.floor((start + end)/2);

		// If element is present at mid, return True
		if (arr[mid]===x) return true;

		// Else look in left or right half accordingly
		else if (arr[mid] < x)
			start = mid + 1;
		else
			end = mid - 1;
	}

	return false;
}

let arr = [1, 4, 6, 70, 85, 89];
let x = 5;

if (iterativeFunction(arr, x, 0, arr.length-1))
	document.write("Element found!<br>");
else document.write("Element not found!<br>");

x = 6;

if (iterativeFunction(arr, x, 0, arr.length-1))
	document.write("Element found!<br>");
else document.write("Element not found!<br>");
</script>									
