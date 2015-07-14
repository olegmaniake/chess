<?php
/**
 * @param array $chess_figure - (ids figures what need load
 * @param array $conditions
 * @param bool $reset
 * @return mixed
 */
function chess_figure_load($chess_figure = array(),$conditions = array(),$reset = FALSE){
  $ids = is_array($chess_figure) ? $chess_figure : array($chess_figure);
  return entity_load('chess_figure',$ids,$conditions,$reset);
}
/**
 * @param array $chess_figures (ids figures what need delete
 */
function chess_figure_delete($chess_figures = array()){
  $ids = is_array($chess_figures) ? $chess_figures : array($chess_figures);
  entity_get_controller('chess_figure')->delete($ids);
}

/**
 * @param array $values
 * @return mixed
 */
function chess_figure_create($values = array()){
  return entity_get_controller('chess_figure')->create($values);
}

/**
 * @param \ChessFigure $chessFigure
 * @return mixed
 */
function chess_figure_save(ChessFigure $chessFigure){
  return $chessFigure->save();
}



/**
 * @return array types for chess figure
 */
function chess_figure_get_types(){
  $bla = db_select('chess_figure_type','c')
    ->fields('c',array('type','label',))
    ->execute()
    ->fetchAllKeyed(0,1);
  return $bla;
}

/**
 * @param $op
 * @param null $chess_figure
 * @param $user
 * @return bool
 */
function chess_figure_access($op,$chess_figure=null,$user){
  global $user;

  if (user_access('admin chess figure', $user)){
    return true;
  }

  $uuid = $user->uid;
  if ($op == 'create' && $uuid != 0){
    return TRUE;
  }
  if (user_access('admin own chess figure') && $uuid == $chess_figure->uid){
    return TRUE;
  }

  return FALSE;
}

function chess_figure_uri($figure){
  if (is_object($figure)){
    $id = (isset($figure->fid) ? $figure->fid : $figure->label);
  return array(
    'path' => 'chess/figure/'.$id,
  );}
}
