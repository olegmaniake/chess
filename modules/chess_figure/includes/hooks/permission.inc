<?php
/**
 *  Implements hook_permission().
 */
function chess_figure_permission() {
  return array(
    'administer chess figure' => array(
      'title' => t('administer chess figure'),
      'description' => t('administer chess figure.'),
      'restrict access' => FALSE,
    ),
    'administer own chess figure' => array(
      'title' => t('administer own chess figure'),
      'description' => t('administer own chess figure.'),
      'restrict access' => TRUE,
    ),
  );
}