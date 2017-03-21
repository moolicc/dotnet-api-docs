   void KnownColorBrightnessExample2( PaintEventArgs^ e )
   {
      Graphics^ g = e->Graphics;

      // Color structures. One is a variable used for temporary storage. The other
      // is a constant used for comparisons.
      Color someColor = Color::FromArgb( 0 );
      Color redShade = Color::FromArgb( 255, 200, 0, 100 );

      // Array to store KnownColor values that match the brightness of the
      // redShade color.
      array<KnownColor>^colorMatches = gcnew array<KnownColor>(15);

      // Number of matches found.
      int count = 0;

      // Iterate through the KnownColor enums until 15 matches are found.
      for ( KnownColor enumValue = (KnownColor)0; enumValue <= KnownColor::YellowGreen && count < 15; enumValue = enumValue + (KnownColor)1 )
      {
         someColor = Color::FromKnownColor( enumValue );
         if ( someColor.GetBrightness() == redShade.GetBrightness() )
                  colorMatches[ count++ ] = enumValue;
      }

      // display the redShade color and its argb value.
      SolidBrush^ myBrush1 = gcnew SolidBrush( redShade );
      System::Drawing::Font^ myFont = gcnew System::Drawing::Font( "Arial",12 );
      int x = 20;
      int y = 20;
      someColor = redShade;
      g->FillRectangle( myBrush1, x, y, 100, 30 );
      g->DrawString( someColor.ToString(), myFont, Brushes::Black, (float)x + 120, (float)y );

      // Iterate through the matches that were found and display each color that
      // corresponds with the enum value in the array. also display the name of
      // The KnownColor.
      for ( int i = 0; i < count; i++ )
      {
         y += 40;
         someColor = Color::FromKnownColor( colorMatches[ i ] );
         myBrush1->Color = someColor;
         g->FillRectangle( myBrush1, x, y, 100, 30 );
         g->DrawString( someColor.ToString(), myFont, Brushes::Black, (float)x + 120, (float)y );
      }
   }