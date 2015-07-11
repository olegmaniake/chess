<?php

/**
 *  Implements hook_entity_info().
 */
function chess_figure_entity_info() {
  $info['chess_figure'] = array(
    'label' => t('Chess figure'),
    'plural label' => t('Chess figures'),
    'entity class' => 'ChessFigure',
    'controller class' => 'ChessFigureController',
    'metadata controller class' => 'ChessFigureMetadataController',
    'base table' => 'chess_figure',
    'fieldable' => TRUE,
    'statusKey' => NULL,
    'translation' => array(
      'entity_translation' => array(
        'class' => 'EntityTranslationDefaultHandler',
        'base path' => 'chess/figure/%chess_figure',
      ),
    ),

    'entity keys' => array(
      'id' => 'fid',
      'bundle' => 'type',
    ),
    'load hook' => 'chess_figure_load',
    'uri callback' => 'chess_figure_uri',
    'access callback' => 'chess_figure_access',
    'module' => 'chess_figure',
    'bundle keys' => array(
      'bundle' => 'type',
    ),
    'view modes' => array(
      'default' => array(
        'label' => t('default'),
        'custom settings' => TRUE,
      ),
    ),
    'bundles' => array(
      'chess_figure' => array(
        'label' => t('Default chess figure'),
        // Человеко-понятное название типа.
        'admin' => array(
          'path' => 'admin/structure/chess/figure/1',
          // Путь, по которому доступна админка.
          'access arguments' => array('administer chess figure'),
          // Права доступа в админку.
          'real path' => 'admin/structure/chess/figure/1',
        ),
      ),
    ),
  );

  $types = db_select('chess_figure', 'c')
    ->fields('c')
    ->execute()
    ->fetchAllAssoc('type');

  foreach ($types as $type => $info_type_figure) {
    $info['chess_figure']['bundles'][$type] = array(
      'label' => $info_type_figure->label, //мітку прсвоемо из бази даних
      'admin' => array(
        'path' => 'admin/structure/chess/figure/%chess_figure_type',
        //шлях за яким буде доступна наша сутність
        'real path' => 'admin/structure/chess/figure/' . $type,
        // реальний шлях до сутності
        'bundle argument' => 4,
        //аргумент в якому передаеться тип сутності
        'access arguments' => array('administer chess figure'),
        //аргумент доступу до підтипу
      ),

    );
  };

  $info['chess_figure_type'] = array(
    'label' => t('Chess figure type'),
    'controller class' => 'ChessFigureTypeController',
    'entity class' => 'ChessFigureType',
    'base table' => 'chess_figure_type',
    'static cache' => FALSE,
    'field cache' => FALSE,
    'uri callback' => 'chess_figure_uri',
    'fieldable' => TRUE,
    'bundle of' => 'chess_figure',
    'exportable' => FALSE,
    'entity keys' => array(
      'id' => 'tid',
      'name' => 'type',
      'label' => 'label',
    ),
    'access callback' => 'chess_figure_access',
    'module' => 'chess_figure',
    'admin ui' => array(
      'path' => 'admin/structure/chess/figure',

      'controller class' => 'ChessFigureTypeUIController',
    ),

  );


  return $info;
}