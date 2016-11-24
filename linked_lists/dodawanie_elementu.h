void insert(int x, int i, elem* &lista)
{
  if(i > 1) // if valid element index
  {
    if (i == 1) // if first list element;
    {
      elem* nowy = new elem; // instantiate new element
      nowy -> dane = x; // apply x as data for that element
      nowy -> nast = lista; // point towards the old list as next element
      lista = nowy; // replace old list with new one
    }
    else // if not first element
    {
      elem* nowy = new elem; // instantiate new element
      nowy -> dane = x; // apply x as data for that element
      elem* poprz = lista; // init old list as previous element

      for (int c = 0; c != (i-2); c++) // loop for applying previous element pointer to each element of the list
      {
        poprz = poprz -> nast;
        if (poprz == NULL) // if previous element to point to doesn't exist, throw a fit and insult the user's mother
          throw runtime_error("Za krotka lista"); // or you know, just show an error. Either works
      }

      nowy -> nast = poprz -> nast; // Ordering Element Pointers Vol II: Return of the Jedi
      poprz -> nast = nowy; // yup still at it. It's the last line tho
    }
  }
  else cout << "Bledne dane"; // throw an error if target element index is <0
}
