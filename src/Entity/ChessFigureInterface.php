<?php

namespace Drupal\chess\Entity;

use Drupal\user\UserInterface;

interface ChessFigureInterface {

  public function setCoordinate($x,$y);

  public function getCoordinate();

  public function setColor($color);

  public function getColor();

  public function setType($type);

  public function getType();

  public function getCreatedTime();

  public function getChangedTime();

  public function getOwner();

  public function getOwnerId();

  public function setOwner(UserInterface $account);

  public function setOwnerId($uid);

}
