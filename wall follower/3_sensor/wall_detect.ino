//--------------------------- wall detection --------------------------------//

void walls() {
  if ( leftSensor < wall_threshold ) {
    leftwall = true ;
  }
  else {
    leftwall = false ;
  }
  if ( rightSensor < wall_threshold ) {
    rightwall = true ;
  }
  else {
    rightwall = false ;

  } if ( frontSensor < front_threshold ) {
    frontwall = true ;
  }
  else {
    frontwall = false ;
  }
}