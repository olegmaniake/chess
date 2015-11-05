<?php

namespace Drupal\chess\Controller;

use Drupal\Core\Entity\EntityInterface;
use Drupal\Core\Entity\EntityListBuilder;
use Drupal\Core\Url;

class ChessFigureListBuilder extends EntityListBuilder {
  public function render() {
    $build['description'] = array(
      '#markup' => $this->t('Chess Figurelist'),
    );
    $build['lable'] = parent::render();

    return $build;
  }

  public function buildHeader() {
    $header['id'] = $this->t('chess figure ID');
    $header['type'] = $this->t('Type');
    $header['color'] = $this->t('Color');
    $header['coordinate'] = $this->t('coordinate');

    return $header + parent::buildHeader();
  }

  public function buildRow(EntityInterface $entity) {
    /*
     * @var $entity \Drupal\chess\Entity\ChessFigure
     */

    $row['id'] = $entity->id();
    $row['type'] = $entity->link();
    $row['color'] = $entity->color->value;
    $row['coordinate'] = $entity->coordinate->value;

    return $row + parent::buildRow($entity);
  }
}
