import Array._

object datastructures extends App{
    var days = Array("Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday");
    //print all elements
    println("Array elements are : ") 
        for ( day <-days ) 
        { 
            print(day)
            print(" ") 
        } 
    //Accessing Elements
    println();
    println(days(0));//Monday
    println(days(6));//Sunday
    
    //update an element
    days(6) = "Sunday Funday";
    println("New Array elements are : ") 
        for ( day <-days ) 
        { 
            print(day)
            print(" ") 
        } 

    //adding elements
    var name = new Array[String](4) 
          
        // Adding element in an array  
        name(0)="sag4x"
        name(1)="for"
        name(2)="datastructures &"
        name(3)="algorithms"
        println("After adding array elements : ") 
          
        for ( m1 <-name ) 
        { 
            print(m1)
            print(" ") 
        } 
        println();

    //concatnate the arrays
    //Make sure to import Array libaray
    var arr1 = Array(1, 2, 3, 4) 
    var arr2 = Array(5, 6, 7, 8) 
  
    var arr3 = concat( arr1, arr2) 
      
    // Print all the array elements 
    for ( x <- arr3 )  
    { 
        print( x );
        print(" "); 
    } 
    println();

    //Complete guide to array append and prepend 
    // Declaring an array 
    val a = Array(45, 52, 61)  
    println("Array a ") 
    for ( x <- a )  
    { 
      print( x );
        print(" "); 
    } 
   println();
    // Appending 1 item 
    val b = a :+ 27 
    println("Array b ") 
    for ( x <- b )  
    { 
      print( x );
        print(" "); 
    } 
   println();
    // Appending 2 item 
    val c = b ++ Array(1, 2) 
    println("Array c ") 
    for ( x <- c )  
    { 
      print( x );
        print(" ");  
    } 
   println();
    // Prepending 1 item 
    val d = 3 +: c  
    println("Array d ") 
    for ( x <- d )  
    { 
      print( x );
        print(" ");  
    } 
   println();
    // Prepending 2 item 
    println("Array e ") 
    val e = Array(10, 25) ++: d 
    for ( x <- e )  
    { 
      print( x );
        print(" ");  
    } 
     println();
}