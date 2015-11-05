<?php

namespace Drupal\chess\Controller;

use Drupal\Core\Access\AccessResult;
use Drupal\Core\Entity\EntityAccessControlHandler;
use Drupal\Core\Entity\EntityInterface;
use Drupal\Core\Session\AccountInterface;

class ChessAccessControlHandler extends EntityAccessControlHandler {
  protected function checkAccess(EntityInterface $entity, $operation, AccountInterface $account){
    switch ($operation){
      case 'view':
        return AccessResult::allowedIfHasPermission($account, 'view chess entity');

      case 'edit':
        return AccessResult::allowedIfHasPermission($account, 'edit chess entity');
      case 'delete':
        return AccessResult::allowedIfHasPermission($account, 'delete chess entity');
    }

    return AccessResult::allowed();
  }
}
